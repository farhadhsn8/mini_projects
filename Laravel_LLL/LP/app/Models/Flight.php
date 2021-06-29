<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;
use Illuminate\Database\Eloquent\SoftDeletes;

class Flight extends Model
{
    use SoftDeletes;
    protected $table = 'flights';
    protected  $fillable=['name'];
//    protected $primaryKey = 'flight_id';
//    protected $keyType = 'string';
//    public $incrementing = false;
//    public $timestamps = false;
//    const CREATED_AT = 'creation_date';
//    const UPDATED_AT = 'updated_date';
//    protected $connection = 'sqlite';
//    protected $attributes = [
//        'delayed' => false,
//    ];

    use HasFactory;
}
