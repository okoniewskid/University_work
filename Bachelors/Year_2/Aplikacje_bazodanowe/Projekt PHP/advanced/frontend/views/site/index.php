<?php
use yii\helpers\Html;
/* @var $this yii\web\View */
$this->title = 'Projekt PHP';
?>
<div class="site-index">

    <div class="jumbotron">
        <h1>Witaj, świecie!</h1>
        
        <?= Html::img('images/jim.gif'); ?>
        <p class="lead">Oto mój projekcik</p>
       
        <p><a class="btn btn-lg btn-success" href="https://inf.ug.edu.pl/">Strona wydziału</a></p>
    </div>

    <div class="body-content">

        <div class="row">
            <div class="col-lg-4">
                <h2>Mój Github</h2>

                <p>Zbiór różnych zadań z okresu studiów.</p>

                <p><a class="btn btn-default" href="https://github.com/okoniewskid">Github &raquo;</a></p>
            </div>
            <div class="col-lg-4">
                <h2>Kursy webowe</h2>

                <p>Kursy pomagające w robieniu takiego czegoś.</p>

                <p><a class="btn btn-default" href="http://www.w3schools.com/">Kursy &raquo;</a></p>
            </div>
            <div class="col-lg-4">
                <h2>Trochę zabawy</h2>

                <p>Najlepsze miejsce do zabicia czasu na zajęciach.</p>

                <p><a class="btn btn-default" href="http://9gag.com/">9gag &raquo;</a></p>
            </div>
        </div>

    </div>
</div>
