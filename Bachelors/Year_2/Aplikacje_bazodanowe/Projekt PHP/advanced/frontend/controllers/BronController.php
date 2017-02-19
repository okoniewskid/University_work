<?php

namespace frontend\controllers;

use Yii;
use common\models\Bron;
use common\models\Rodzaj;
use common\models\Obrazenia;
use common\models\BronSearch;
use yii\web\Controller;
use yii\web\NotFoundHttpException;
use yii\filters\VerbFilter;
use yii\helpers\ArrayHelper;

/**
 * BronController implements the CRUD actions for Bron model.
 */
class BronController extends Controller
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
     * Lists all Bron models.
     * @return mixed
     */
    public function actionIndex()
    {
        $searchModel = new BronSearch();
        $dataProvider = $searchModel->search(Yii::$app->request->queryParams);

        return $this->render('index', [
            'searchModel' => $searchModel,
            'dataProvider' => $dataProvider,
        ]);
    }

    /**
     * Displays a single Bron model.
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
     * Creates a new Bron model.
     * If creation is successful, the browser will be redirected to the 'view' page.
     * @return mixed
     */
    public function actionCreate()
    {
        $model = new Bron();

        $rodzaje = Rodzaj::find()
            ->orderBy('Rodzaj')
            ->all();
        $obrazenia = Obrazenia::find()
            ->orderBy('Obrazenia')
            ->all();

        $rodzaje = ArrayHelper::map($rodzaje, 'id', 'Rodzaj');
        $obrazenia = ArrayHelper::map($obrazenia, 'id', 'Obrazenia');

        if ($model->load(Yii::$app->request->post()) && $model->save()) {
            return $this->redirect(['view', 'id' => $model->id]);
        } else {
            return $this->render('create', [
                'model' => $model,
                'rodzaje' => $rodzaje,
                'obrazenia' => $obrazenia,
            ]);
        }
    }

    /**
     * Updates an existing Bron model.
     * If update is successful, the browser will be redirected to the 'view' page.
     * @param integer $id
     * @return mixed
     */
    public function actionUpdate($id)
    {
        $model = $this->findModel($id);

        $rodzaje = Rodzaj::find()
            ->orderBy('Rodzaj')
            ->all();
        $obrazenia = Obrazenia::find()
            ->orderBy('Obrazenia')
            ->all();

        $rodzaje = ArrayHelper::map($rodzaje, 'id', 'Rodzaj');
        $obrazenia = ArrayHelper::map($obrazenia, 'id', 'Obrazenia');

        if ($model->load(Yii::$app->request->post()) && $model->save()) {
            return $this->redirect(['view', 'id' => $model->id]);
        } else {
            return $this->render('update', [
                'model' => $model,
                'rodzaje' => $rodzaje,
                'obrazenia' => $obrazenia,
            ]);
        }
    }

    /**
     * Deletes an existing Bron model.
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
     * Finds the Bron model based on its primary key value.
     * If the model is not found, a 404 HTTP exception will be thrown.
     * @param integer $id
     * @return Bron the loaded model
     * @throws NotFoundHttpException if the model cannot be found
     */
    protected function findModel($id)
    {
        if (($model = Bron::findOne($id)) !== null) {
            return $model;
        } else {
            throw new NotFoundHttpException('The requested page does not exist.');
        }
    }
}
