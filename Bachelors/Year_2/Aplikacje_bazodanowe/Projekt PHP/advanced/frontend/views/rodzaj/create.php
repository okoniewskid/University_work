<?php

use yii\helpers\Html;


/* @var $this yii\web\View */
/* @var $model common\models\Rodzaj */

$this->title = Yii::t('app', 'Stwórz rodzaj');
$this->params['breadcrumbs'][] = ['label' => Yii::t('app', 'Rodzaje'), 'url' => ['index']];
$this->params['breadcrumbs'][] = $this->title;
?>
<div class="rodzaj-create">

    <h1><?= Html::encode($this->title) ?></h1>

    <?= $this->render('_form', [
        'model' => $model,
    ]) ?>

</div>
