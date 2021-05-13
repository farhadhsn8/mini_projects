/*document.onclick=function(){
    alert("you clicked somewhere !!!");
};
*/

/*function someevent()
{
    var myimg = document.getElementById("mainImage");
    myimg.onclick=function()
    {
        alert("you clicked the image");
    }
}

window.onload=function()
{
    this.someevent();
};
*/

var mypara = document.getElementsByTagName("h1");

function myworm()
{
   for(let i = 0 ; i<= mypara.length; i++)
   {
       mypara[i].setAttribute("background-color",red);
   }
}


setInterval(myworm,200);
document.onclick=function()
{
    clearInterval(my_timer);
};
