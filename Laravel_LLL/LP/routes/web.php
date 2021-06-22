<?php

use Illuminate\Support\Facades\Route;

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/

Route::get('/', function () {
    return view('welcome');
});


Route::get('/about',function (){
    echo "<h1>jalase avval tamrin</h1>";
});


Route::get('/about/{yourage}/{yourname}',function ($age ,$name){
    echo "<h2>سن شما '$age' میباشد </h2> ";
    echo "      اسم شما$name  است ";
});
