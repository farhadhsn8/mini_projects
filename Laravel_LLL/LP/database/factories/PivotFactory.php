<?php

namespace Database\Factories;

use App\Models\Pivot;
use Illuminate\Database\Eloquent\Factories\Factory;
use Illuminate\Support\Str;

class PivotFactory extends Factory
{
    /**
     * The name of the factory's corresponding model.
     *
     * @var string
     */
    protected $model = Pivot::class;

    /**
     * Define the model's default state.
     *
     * @return array
     */
    public function definition()
    {
        return [
            'warehouse_id' => rand(1,8),
            'product_id' => rand(1,20),
        ];
    }
}
