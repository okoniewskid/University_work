<?php

namespace frontend\controllers;

use Yii;
use common\models\Postac;
use common\models\Rasa;
use common\models\Bron;
use common\models\Pancerz;
use common\models\PostacSearch;
use yii\web\Controller;
use yii\web\NotFoundHttpException;
use yii\filters\VerbFilter;
use yii\helpers\ArrayHelper;

/**
 * PostacController implements the CRUD actions for Postac model.
 */
class PostacController extends Controller
{
    public function behaviors()
    {
        return [
            'verbs' => [
                'class' => VerbFilter::className(),
                'actions' => [
                    'delete' => ['post'],
                ],
            ],
        ];
    }

    /**
     * Lists all Postac models.
     * @return mixed
     */
    public function actionIndex()
    {
        $searchModel = new PostacSearch();
        $dataProvider = $searchModel->search(Yii::$app->request->queryParams);

        return $this->render('index', [
            'searchModel' => $searchModel,
            'dataProvider' => $dataProvider,
        ]);
    }

    /**
     * Displays a single Postac model.
     * @param integer $id
     * @return mixed
     */
    public function actionView($id)
    {
        return $this->render('view', [
            'model' => $this->findModel($id),
        ]);
    }

    /**
     * Creates a new Postac model.
     * If creation is successful, the browser will be redirected to the 'view' page.
     * @return mixed
     */
    public function actionCreate()
    {
        $model = new Postac();

        $rasy = Rasa::find()
            ->orderBy('Nazwa')
            ->all();
        $bronie = Bron::find()
            ->orderBy('Nazwa')
            ->all();
        $pancerze = Pancerz::find()
            ->orderBy('Nazwa')
            ->all();


        $rasy = ArrayHelper::map($rasy, 'id', 'Nazwa');
        $bronie = ArrayHelper::map($bronie, 'id', 'Nazwa');
        $pancerze = ArrayHelper::map($pancerze, 'id', 'Nazwa');

        if ($model->load(Yii::$app->request->post()) && $model->save()) {
            return $this->redirect(['view', 'id' => $model->id]);
        } else {
            return $this->render('create', [
                'model' => $model,
                'rasy' => $rasy,
                'bronie' => $bronie,
                'pancerze' => $pancerze,
            ]);
        }
    }

    /**
     * Updates an existing Postac model.
     * If update is successful, the browser will be redirected to the 'view' page.
     * @param integer $id
     * @return mixed
     */
    public function actionUpdate($id)
    {
        $model = $this->findModel($id);

        $rasy = Rasa::find()
            ->orderBy('Nazwa')
            ->all();
        $bronie = Bron::find()
            ->orderBy('Nazwa')
            ->all();
        $pancerze = Pancerz::find()
            ->orderBy('Nazwa')
            ->all();

        $rasy = ArrayHelper::map($rasy, 'id', 'Nazwa');
        $bronie = ArrayHelper::map($bronie, 'id', 'Nazwa');
        $pancerze = ArrayHelper::map($pancerze, 'id', 'Nazwa');

        if ($model->load(Yii::$app->request->post()) && $model->save()) {
            return $this->redirect(['view', 'id' => $model->id]);
        } else {
            return $this->render('update', [
                'model' => $model,              
                'rasy' => $rasy,
                'bronie' => $bronie,
                'pancerze' => $pancerze,
            ]);
        }
    }

    /**
     * Deletes an existing Postac model.
     * If deletion is successful, the browser will be redirected to the 'index' page.
     * @param integer $id
     * @return mixed
     */
    public function actionDelete($id)
    {
        $this->findModel($id)->delete();

        return $this->redirect(['index']);
    }

    /**
     * Finds the Postac model based on its primary key value.
     * If the model is not found, a 404 HTTP exception will be thrown.
     * @param integer $id
     * @return Postac the loaded model
     * @throws NotFoundHttpException if the model cannot be found
     */
    protected function findModel($id)
    {
        if (($model = Postac::findOne($id)) !== null) {
            return $model;
        } else {
            throw new NotFoundHttpException('The requested page does not exist.');
        }
    }
}
