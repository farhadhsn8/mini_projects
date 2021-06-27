<?php

use Illuminate\Support\Facades\Auth;
use Illuminate\Support\Facades\DB;
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

Auth::routes();

Route::get('/home', [App\Http\Controllers\HomeController::class, 'index'])->name('home');



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


Route::prefix('/flights')->group(function (){
    Route::get('',function (){
        $flights = DB::table('flights')->get();
        return view('flights')->with('flights',$flights);
    });


    Route::get('/insert/{name}/{airline}',function ($name,$airline){
         DB::table('flights')->insert([
            'name'=>$name,
            'airline'=>$airline,
            'information' =>'safar khoobi dashte bashid...'
        ]);

        $flights = DB::table('flights')->get();
        return view('flights')->with('flights',$flights);

    });

    Route::get('/update/{id}/{name}/{airline}',function ($id ,$name,$airline){
         DB::table('flights')->where('id',$id)->update([
            'name'=>$name,
            'airline'=>$airline,
            'information' =>'safar khoobi nadashte bashid!!!!'
        ]);

        $flights = DB::table('flights')->get();
        return view('flights')->with('flights',$flights);
    });


});

