







 















/*
variables:
      var myemail= "someone@some.com";
      var year= "1990/08/11";
      year=true;
      var month=06 , day =28;
      myemail+1 // someone@some.com1
*/

/*
---------------------------------------------------
---------------------------------------------------
  if (age > 19)
    alert("Adult");
  else{
    alert("you are young!");
}
----------------------------------------------------
----------------------------------------------------
operators:
  score = score +10 ;
  score+=10;
  var a = score % 3;
  a++;
  a--;
  ---------------------------------------------------
------------------------------------------------------
"==" or "==="
    a=5;
    b="5";
    a==b    true
    a===b   false  {better}
-----------------------------------------------------
-----------------------------------------------------
Ternary: " : ? "

  var player1= 500;
  var player2= 600;
  var highScore = (player1>player2)?player1:player2;
---------------------------------------------------------
---------------------------------------------------------
alert("bye world!");
console.log("salam");   not for user , its for programmer...
console.debug("salam");
console.error("salam");
-----------------------------------------------------------
-----------------------------------------------------------
LOOPS:
    while (a<10) {
      console.log(a);
      a++;
    }
------------------------------------------------------------
   do{
   console.log(a);
   a++;
 }while(a<10);
------------------------------------------------------------
for (var i = 0; i < 30; i=i+4) {
  console.log(i**2);
}
-----------------------------------------------------------
------------------------------------------------------------
Break & continue:
for (var i = 0; i < 30; i=i+4) {
  if (i===13)
    Break;
  console.log(i**2);
}
--------------------------------------------------------------
--------------------------------------------------------------
Function:
  Function create(number)
  {
   console.log("we are in the function "+ number);
}
---------------------------------------------------------------
---------------------------------------------------------------
Array:
   var arr1 = [50, 60 ,"mehrdad"];
-----------------------------------------------------------------
  var arr2 = [];
  arr2[0]=5;
  arr2[1]=18;
  arr2[2]="mehrdad";
-----------------------------------------------------------------
  var arr3 = new Array();
  
  -----------------------------------------------------------------
  var arr4 = Array(100);
  
  -----------------------------------------------------------------
  arr4.length;
  --------------------------------------------------------------
  --------------------------------------------------------------
  methods:
    functins of objects.
    arrays are object.
----------------------------------------------------------------
    var arr2=[10, 20, 30, 40, 50, 60, 70, 80, 90];
    var reversedarr2=arr2.reverse();
    console.log(reversedarr2);
---------------------------------------------------------------
---------------------------------------------------------------
var mylinks = document.getElementsByTagName("a");
var myitem = document.getElementsByTagName("li");
console.log(mylinks);
--------------------------------------------------------------
alert(abc*5);
NaN : not a number
--------------------------------------------------------------
var x= 5;
var y = "farhad";
if(!isNaN(y))
  alert(y**y);
else
  alert("its not a number!");
--------------------------------------------------------------
Math:
    var x= 206.7;
    var y = Math.round(x);
    console.log(y); 
  --------------------------
  var y = 1+Math.random()*31;
  console.log(y);
  ----------------------------
  var y = Math.min(12,23,45);
  console.log(y);
  -----------------------------
  console.log(Math.PI);
  ------------------------------------------------------------------
string:
    var str = "farhad";
    str.toUpperCase()
    console.log(str.toUpperCase());
    -------------------------------
    var a= ["farhad", "hosseini", "seyed"];
    console.log(a[1][6]);           //n
    --------------------------------
    var str = "farhad hosseini";
    var y = str.split(" ");
    console.log(y);
    -----------------------------
    var a = "farhad hosseini";
    var b = a.search("ho");
    console.log(b);
    -----------------------------
    var a = "farhad hosseini";
    var b = a.search("ho");
    console.log(b);
    var c = a.slice(3,8);
    var d = a.substring(3,6);
    ---------------------------------------------------------
Date:
    var a = new Date();
    a.getFullYear;
    a.getMonth();
    a.getTime();
    a.getTimezoneOffset();
    a.setDate();
    a.setHours();
---------------------------------------------------------------
objects:
    var player = new Object();
    player.name="fred";
    player.score=1750;
    player.renk=11;
    function showinfo()
    {
      console.log(player.score);
    }
    showinfo();

    var student={name:"jake",studentnumber="9612358016",branch="ce"};


*/
