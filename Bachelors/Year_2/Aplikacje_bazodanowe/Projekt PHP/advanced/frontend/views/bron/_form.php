<?php

use yii\helpers\Html;
use yii\widgets\ActiveForm;

/* @var $this yii\web\View */
/* @var $model common\models\Bron */
/* @var $form yii\widgets\ActiveForm */
?>

<div class="bron-form">

    <?php $form = ActiveForm::begin(); ?>

    <?= $form->field($model, 'Nazwa')->textInput(['maxlength' => 255]) ?>

    <?= $form->field($model, 'rodzaj_id')->dropDownList($rodzaje)->label('Rodzaj obrażeń') ?>

    <?= $form->field($model, 'obrazenia_id')->dropDownList($obrazenia)->label('Wielkość obrażeń') ?>

    <div class="form-group">
        <?= Html::submitButton($model->isNewRecord ? Yii::t('app', 'Stwórz') : Yii::t('app', 'Aktualizuj'), ['class' => $model->isNewRecord ? 'btn btn-success' : 'btn btn-primary']) ?>
    </div>

    <?php ActiveForm::end(); ?>

</div>
