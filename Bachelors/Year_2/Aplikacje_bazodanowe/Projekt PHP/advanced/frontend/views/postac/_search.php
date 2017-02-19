<?php

use yii\helpers\Html;
use yii\widgets\ActiveForm;

/* @var $this yii\web\View */
/* @var $model common\models\PostacSearch */
/* @var $form yii\widgets\ActiveForm */
?>

<div class="postac-search">

    <?php $form = ActiveForm::begin([
        'action' => ['index'],
        'method' => 'get',
    ]); ?>

    <?= $form->field($model, 'id') ?>

    <?= $form->field($model, 'rasa_id') ?>

    <?= $form->field($model, 'Imie') ?>

    <?= $form->field($model, 'Wiek') ?>

    <?= $form->field($model, 'Wzrost') ?>

    <?php // echo $form->field($model, 'Waga') ?>

    <?php // echo $form->field($model, 'Zloto') ?>

    <?php // echo $form->field($model, 'bron_id') ?>

    <?php // echo $form->field($model, 'pancerz_id') ?>

    <?php // echo $form->field($model, 'Data_utworzenia') ?>

    <div class="form-group">
        <?= Html::submitButton(Yii::t('app', 'Search'), ['class' => 'btn btn-primary']) ?>
        <?= Html::resetButton(Yii::t('app', 'Reset'), ['class' => 'btn btn-default']) ?>
    </div>

    <?php ActiveForm::end(); ?>

</div>
