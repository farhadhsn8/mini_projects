<?php

namespace App\Http\Controllers;

use App\Mail\TestMail;
use App\Models\Warehouse;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\Mail;
use Illuminate\Support\Facades\Validator;

class WarehouseController extends Controller
{


    public function showAll(Request $request){
        $warehouses = Warehouse::all();
//        $value = $request->session();
//        dd($value);
         return view('warehouse_management.warehouse.warehouses')->with('warehouses',$warehouses);
    }



   public function create(){
        return view('warehouse_management.warehouse.addWarehouse');
    }




    public function store(){
        // dd(request()->all());
        $validator = Validator::make(request()->all(), [
            'name' => 'required|max:255',
            'address' => 'required',
        ]);
        if ($validator->fails()) {
            return redirect(\route('warehouse.create'))
                ->withErrors($validator)
                ->withInput();
        }
        Warehouse::create([
            'name'=>request('name'),
            'address' => \request('address')
        ]);
        return redirect(route('warehouses.show'));
    }




    public function show1(Warehouse $warehouse){
        return view('warehouse_management.warehouse.updateWarehouse')->with('warehouse',$warehouse);
    }







   public function update(Warehouse $warehouse){
        // dd(request()->all());
        $validator = Validator::make(request()->all(), [
            'name' => 'required|max:255',
            'address' => 'required',
        ]);
        if ($validator->fails()) {
            return redirect(\route('warehouse.create'))
                ->withErrors($validator)
                ->withInput();
        }

        $warehouse->update([
            'name'=>request('name'),
            'address' => \request('address')
        ]);
        return redirect(\route('warehouses.show'));
    }




    public function delete($id){
        $warehouse=Warehouse::findOrFail($id);
        $warehouse->delete();
        Mail::to('farhadhsn8@gmail.com')->send(new TestMail($warehouse));
        return back();
    }
}
