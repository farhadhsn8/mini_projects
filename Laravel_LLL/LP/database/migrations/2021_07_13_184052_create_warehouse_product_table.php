<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

class CreateWarehouseProductTable extends Migration
{
    /**
     * Run the migrations.
     *
     * @return void
     */
    public function up()
    {
        Schema::create('warehouse_product', function (Blueprint $table) {
            $table->bigIncrements('warehouse_id');
            $table->bigIncrements('product_id');
            $table->timestamps();
            $table->unique(['warehouse_id' , 'product_id']);
            $table->foreign('product_id')->references('id')
                ->on('products')->onDelete('cascade');
            $table->foreign('warehouse_id')->references('id')
                ->on('warehouses')->onDelete('cascade');
        });
    }

    /**
     * Reverse the migrations.
     *
     * @return void
     */
    public function down()
    {
        Schema::dropIfExists('warehouse_product');
    }
}
