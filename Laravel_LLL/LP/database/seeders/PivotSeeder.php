<?php

namespace Database\Seeders;

use App\Models\Pivot;
use Illuminate\Database\Seeder;

class PivotSeeder extends Seeder
{
    /**
     * Run the database seeds.
     *
     * @return void
     */
    public function run()
    {
        Pivot::factory()
            ->count(50)
            ->create();
    }
}
