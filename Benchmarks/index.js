/* Need to create a local server for fetching data from directory( if running on local machine)
  use:python -m http.server
  or use:http-server get it from (npm install http-server)
*/
const filesName=["GMP.json","mpDecimal.json","MPFR.json","NTL.json","realLib.json","iRRAM.json","Real_old.json","Real_new.json"];
const ignore=["BM_overhead","BM_Initialize"]
const Functions = new Map();


filesName.forEach( name=>{
  fetch(name).then(response =>response.json()).then(data=>{

        data.benchmarks.forEach((item, i) => {
          var [function_name,len]=item.name.split("/")

          if(ignore.includes(function_name)===false){
            if(Functions.has(function_name)===false){
                Functions.set(function_name,new Map());
            }

            if(Functions.get(function_name).has(name)===false){
              Functions.get(function_name).set(name,[]);
            }

            Functions.get(function_name).get(name).push({x:len,y:item.cpu_time});
          }

        });
      });

});


function main(){

  Functions.forEach( (value,key) => {
        series=[];

        value.forEach( (value,key) =>{
          series.push({name:key,points:value});
        });
        JSC.Chart(key,{
          title_label_text:key,
          series:series});
  });

}

setTimeout(main,1000);
