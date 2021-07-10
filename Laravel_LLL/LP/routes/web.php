<?php

use App\Http\Controllers\ArticleController;
use App\Http\Controllers\WarehouseController;
use App\Models\Flight;
use App\Models\User;
use App\Models\Warehouse;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\Auth;
use Illuminate\Support\Facades\DB;
use Illuminate\Support\Facades\Route;
use Illuminate\Support\Facades\Validator;

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



Route::get('f0',function (){
    $i=1;
    foreach (Flight::all() as $flight) {
        echo $i." - ".$flight->name."<br>";
        $i++;
    }
});

Route::get('f1',function (){
    $i=1;
    $flights = Flight::where('airline', 'hosseini')
        ->orderBy('name')
        ->take(2)
        ->get();
    foreach ($flights as $flight) {
        echo $i." - ".$flight->name."<br>";
        $i++;
    }
});


Route::get('f2',function (){
    Flight::chunk(10, function ($flights) {
        $i=1;
        foreach ($flights as $flight) {
            echo $i." - ".$flight->name."<br>";
            $i++;

        }
    });
});


Route::get('f3',function (){
    $i=1;
    $flight = Flight::find(1);

    echo $i." - ".$flight->name."<br>";

});


Route::get('f4',function (){
    $i=1;
    $flight = Flight::findOrFail(8);
    echo $i." - ".$flight->name."<br>";


});


//Route::get('f5',function (){
//    $flight = Flight::firstOrCreate([
//        'name' => 'London to Paris']
//    );
//    $i=1;
//    $flight = Flight::findOrFail('name','London to Paris');
//    echo $i." - ".$flight->name."<br>";
//
//});


//$count = Flight::where('active', 1)->count();
//
//$max = Flight::where('active', 1)->max('price');


Route::get('f6',function (){
    $flight = new Flight;

    $flight->name = 'farhad';
    $flight->airline = 'hosseini';
    $flight->information = 'farhad  -  hosseini';

    $flight->save();


});
/*$flight = Flight::create([
    'name' => 'London to Paris',
]);*/


Route::get('f7',function (){
    $flight = Flight::where('airline', 'hosseini')
        ->first();

    $flight->name = 'mahdi';
    $flight->airline = 'benvidi';


    $flight->save();


});
/*
Flight::where('active', 1)
    ->where('destination', 'San Diego')
    ->update(['delayed' => 1]);*/


Route::get('/',[WarehouseController::class, 'showAll'])->name('warehouses.show');

Route::get('warehouse/create',[WarehouseController::class, 'create'])->name('warehouse.create');

Route::post('warehouse/store' ,[WarehouseController::class, 'store'])->name('warehouse.store');

Route::get('warehouse/show1/{warehouse}',[WarehouseController::class, 'show1'])->name('warehouse.show1')->middleware('auth');

Route::put('warehouse/update/{warehouse}' ,[WarehouseController::class, 'update'])->name('warehouse.update');

Route::delete('warehouse/delete/{warehouse}',[WarehouseController::class, 'delete'])->name('warehouse.delete');

Route::get('article',[ArticleController::class, 'show'])->name('article.show');

//$deletedRows = Flight::where('active', 0)->delete();

