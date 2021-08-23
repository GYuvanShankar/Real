const fs = require("fs");


fs.readFile("iRRAM_unprocessed.json",(err,resp)=>{
  if(err){
    console.log("Error Reading file: ",err);
    return;
  }
  else{
    console.log("File reading Successfull.\n");

    const overheads= new Map();
    var inputJson=JSON.parse(resp);

    //Loop over all benchmarks to find BM_overhead and store it along with its lenght.
    for(var i=0;i<(inputJson.benchmarks.length);++i){
      const obj=inputJson.benchmarks[i];
      var [functionName,len]=obj.name.split('/');

      if(functionName=="BM_overhead"){
        overheads.set(len,[obj.real_time,obj.cpu_time])
      }
    }
    //To hold modified benchmarks obj.
    var updatedBenchmarks=[];

    for(var i=0;i<(inputJson.benchmarks.length);++i){
      const obj=inputJson.benchmarks[i];
      var [functionName,len]=obj.name.split('/');

      if(functionName!="BM_overhead"){

        obj.real_time-=overheads.get(len)[0];
        obj.cpu_time-=overheads.get(len)[1];
      }

      updatedBenchmarks.push(obj);
    }

    var outputJson={"context":inputJson.context,"benchmarks":updatedBenchmarks};
    fs.writeFile("iRRAM.json",JSON.stringify(outputJson),(err,res)=>{
      if(err)
      console.log("Error: ",err);
      else console.log("File modified.");
    })
  }
})
