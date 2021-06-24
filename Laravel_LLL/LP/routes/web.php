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




Route::prefix('/about')->group(function (){
    Route::get('',function (){
        echo "<h1>jalase avval tamrin</h1>";
    });


    Route::get('/{yourage}/{yourname}',function ($age ,$name){
        echo "<h2>سن شما '$age' میباشد </h2> ";
        echo "      اسم شما$name  است ";
    });

    Route::get('/{yourage}',function ($age){
        return view('age')->with('age',$age);
    });


});
