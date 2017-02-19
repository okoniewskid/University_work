<?php

use yii\helpers\Html;


/* @var $this yii\web\View */
/* @var $model common\models\Obrazenia */

$this->title = Yii::t('app', 'Stwórz obrażenia');
$this->params['breadcrumbs'][] = ['label' => Yii::t('app', 'Obrażenia'), 'url' => ['index']];
$this->params['breadcrumbs'][] = $this->title;
?>
<div class="obrazenia-create">

    <h1><?= Html::encode($this->title) ?></h1>

    <?= $this->render('_form', [
        'model' => $model,
    ]) ?>

</div>
